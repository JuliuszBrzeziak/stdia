class Bug:

    """dfghjk"""

    c = 0  # global variable

    def __init__(self):

        self.id = Bug.c
        Bug.c += 1

    def __del__(self):
        Bug.c -= 1
        print("Koniec")

    def __str__(self):
        return "{self.id}".format(self=self)


bugs = []

for i in range(10):
    bugs.append(Bug())
    print(bugs[-1])