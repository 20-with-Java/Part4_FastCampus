class Cube:
    def __init__(self, area):
        self.area = area

    def check(self):
        for i in range(24):
            base = [0, 4, 8, 12, 16, 20]
            if self.area[i] != self.area[base[i // 4]]:
                return False
        return True

    def r(self):
        temp1 = self.area[1]
        temp2 = self.area[3]
        self.area[1] = self.area[5]
        self.area[3] = self.area[7]
        self.area[5] = self.area[9]
        self.area[7] = self.area[11]
        self.area[9] = self.area[22]
        self.area[11] = self.area[20]
        self.area[22] = temp1
        self.area[20] = temp2

    def u(self):
        temp1 = self.area[4]
        temp2 = self.area[5]
        self.area[4] = self.area[12]
        self.area[5] = self.area[13]
        self.area[12] = self.area[20]
        self.area[13] = self.area[21]
        self.area[20] = self.area[16]
        self.area[21] = self.area[17]
        self.area[16] = temp1
        self.area[17] = temp2

    def f(self):
        temp1 = self.area[2]
        temp2 = self.area[3]
        self.area[2] = self.area[15]
        self.area[3] = self.area[13]
        self.area[15] = self.area[9]
        self.area[13] = self.area[8]
        self.area[9] = self.area[16]
        self.area[8] = self.area[18]
        self.area[16] = temp1
        self.area[18] = temp2

def exit_if_true(b):
    if b:
        print(1)
        exit(0)

# 입력을 받고 Cube 객체를 생성
area = list(map(int, input().split()))
cube = Cube(area)

# 큐브 동작 수행 후 검사
cube.r()
exit_if_true(cube.check())
cube.r()
cube.r()
exit_if_true(cube.check())
cube.r()

cube.u()
exit_if_true(cube.check())
cube.u()
cube.u()
exit_if_true(cube.check())
cube.u()

cube.f()
exit_if_true(cube.check())
cube.f()
cube.f()
exit_if_true(cube.check())

print(0)
