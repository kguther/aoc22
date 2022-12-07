from __future__ import annotations

import itertools


class Directory:
    def __init__(self, parent):
        self.subdirs = {}
        self.files = {}
        self.parent = parent

    def add_file(self, filename, filesize):
        self.files[filename] = filesize

    def add_subdirectory(self, dirname):
        self.subdirs[dirname] = Directory(self)

    def size(self):
        file_sizes = sum(self.files.values())
        subdir_sizes = sum(dir.size() for dir in self.subdirs.values())
        return file_sizes + subdir_sizes

    def all_subdirs(self):
        return [self] + list(itertools.chain.from_iterable(dir.all_subdirs() for dir in self.subdirs.values()))
