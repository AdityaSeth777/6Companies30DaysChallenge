class Solution:
    def __init__(self, m, n):
        self.m = m
        self.n = n
        self.flipped = Counter()
        #Aditya Seth.
    def flip(self):
        i, j = random.randint(0, self.m-1), random.randint(0, self.n-1)
        while self.flipped[(i, j)] == 1:
            i, j = random.randint(0, self.m-1), random.randint(0, self.n-1)
        self.flipped[(i, j)] = 1
        return (i, j)
    def reset(self):
        self.flipped = Counter()