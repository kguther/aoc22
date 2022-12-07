from directory import Directory


class Parser:
    def __init__(self):
        self.root = Directory(None)
        self.current_directory = self.root

    def _process_command(self, parts):
        if parts[1] == "cd":
            if parts[2] == "/":
                self.current_directory = self.root
            elif parts[2] == "..":
                self.current_directory = self.current_directory.parent
            else:
                self.current_directory = self.current_directory.subdirs[parts[2]]

    def _process_command_output(self, parts):
        if parts[0] == "dir":
            self.current_directory.add_subdirectory(parts[1])
        else:
            self.current_directory.add_file(parts[1], int(parts[0]))


    def _process_cl_output(self, line):
        parts = line.rstrip().split(" ")
        if parts[0] == "$":
            return self._process_command(parts)
        else:
            self._process_command_output(parts)

    def read_directory(self, filename):
        with open(filename) as ifile:
            for line in ifile:
                self._process_cl_output(line)
        return self.root