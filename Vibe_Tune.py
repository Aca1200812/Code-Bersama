import sys
import os
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QLabel, QFileDialog, QListWidget, QSlider
from PyQt5.QtCore import QTimer, Qt
import pygame
from mutagen.mp3 import MP3

class MusicPlayer(QWidget):
    def __init__(self):
        super().__init__()
        self.playlist = []
        self.current_index = 0
        self.is_playing = False
        self.seeking = False
        self.last_seek_pos = None
        pygame.mixer.init()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('VibeTunes')
        self.resize(500, 400)
        layout = QVBoxLayout()

        self.label = QLabel('No song loaded')
        layout.addWidget(self.label)

        self.button_load = QPushButton('Music Folder')
        self.button_load.clicked.connect(self.load_folder)
        layout.addWidget(self.button_load)

        self.button_play = QPushButton('Play')
        self.button_play.clicked.connect(self.play)
        layout.addWidget(self.button_play)

        self.button_pause = QPushButton('Pause/Unpause')
        self.button_pause.clicked.connect(self.pause)
        layout.addWidget(self.button_pause)

        self.button_next = QPushButton('Next')
        self.button_next.clicked.connect(self.next)
        layout.addWidget(self.button_next)

        self.button_prev = QPushButton('Previous')
        self.button_prev.clicked.connect(self.prev)
        layout.addWidget(self.button_prev)

        self.song_list = QListWidget()
        self.song_list.itemDoubleClicked.connect(self.play_selected)
        layout.addWidget(self.song_list)

        self.slider = QSlider(Qt.Horizontal)
        self.slider.setMinimum(0)
        self.slider.setMaximum(100)
        self.slider.sliderReleased.connect(self.slider_seek)
        layout.addWidget(self.slider)

        self.timer = QTimer()
        self.timer.timeout.connect(self.update_slider)

        self.setLayout(layout)

    def load_folder(self):
        folder = QFileDialog.getExistingDirectory(self, 'Select Music Folder')
        if folder:
            self.playlist = [os.path.join(folder, f) for f in os.listdir(folder) if f.lower().endswith('.mp3')]
            self.song_list.clear()
            for song in self.playlist:
                audio = MP3(song)
                length = audio.info.length
                minutes = int(length // 60)
                seconds = int(length % 60)
                self.song_list.addItem(f"{os.path.basename(song)} ({minutes}:{seconds:02d})")
            if self.playlist:
                self.current_index = 0
                self.song_list.setCurrentRow(0)
                self.label.setText(f'Loaded playlist with {len(self.playlist)} songs')

    def play(self, from_seek=False):
        if self.playlist:
            pygame.mixer.music.load(self.playlist[self.current_index])
            pygame.mixer.music.play()
            self.is_playing = True
            self.label.setText(f'Playing: {os.path.basename(self.playlist[self.current_index])}')
            self.song_list.setCurrentRow(self.current_index)
            audio = MP3(self.playlist[self.current_index])
            self.slider.setMaximum(int(audio.info.length))
            if not from_seek:
                self.slider.setValue(0)
                self.timer.start(1000)

    def pause(self):
        if self.is_playing:
            pygame.mixer.music.pause()
            self.is_playing = False
            self.label.setText(f'Paused: {os.path.basename(self.playlist[self.current_index])}')
            self.timer.stop()
        else:
            pygame.mixer.music.unpause()
            self.is_playing = True
            self.label.setText(f'Playing: {os.path.basename(self.playlist[self.current_index])}')
            self.timer.start(1000)

    def next(self):
        if self.playlist:
            self.current_index = (self.current_index + 1) % len(self.playlist)
            self.play()

    def prev(self):
        if self.playlist:
            self.current_index = (self.current_index - 1) % len(self.playlist)
            self.play()

    def play_selected(self, item):
        index = self.song_list.row(item)
        self.current_index = index
        self.play()

    def slider_seek(self):
        self.seeking = True
        position = self.slider.value()
        self.seek(position)
        self.last_seek_pos = position
        self.seeking = False

    def seek(self, position):
        if self.playlist:
            pygame.mixer.music.stop()
            pygame.mixer.music.load(self.playlist[self.current_index])
            pygame.mixer.music.play(start=position)
            self.is_playing = True
            self.slider.setValue(position)
            self.label.setText(f'Playing: {os.path.basename(self.playlist[self.current_index])}')
            self.song_list.setCurrentRow(self.current_index)
            audio = MP3(self.playlist[self.current_index])
            self.slider.setMaximum(int(audio.info.length))
            self.timer.start(1000)

    def update_slider(self):
        if pygame.mixer.music.get_busy():
            if self.last_seek_pos is not None:
                self.slider.setValue(self.last_seek_pos)
                QTimer.singleShot(10000, self.reset_last_seek)
            else:
                position = pygame.mixer.music.get_pos() / 1000  # Convert milliseconds to seconds
                self.slider.setValue(int(position))
        else:
            self.timer.stop()

    def reset_last_seek(self):
        self.last_seek_pos = None

if __name__ == '__main__':
    app = QApplication(sys.argv)
    player = MusicPlayer()
    player.show()
    sys.exit(app.exec_())