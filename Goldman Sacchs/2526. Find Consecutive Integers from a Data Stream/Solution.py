class DataStream:

    def __init__(self, value: int, k: int):
        self.val = value
        self.k = k
        self.i = 0
    # Aditya Seth.    
    def consec(self, num: int) -> bool:
        if(num == self.val):
            self.i += 1
        if(num != self.val):
            self.i = 0
        if((self.i == self.k or self.i > self.k)  and num == self.val):
            return True
        else:
            return False