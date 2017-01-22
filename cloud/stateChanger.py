
state = 0
left = 0
right = 0


def getState():
    return state


def controller():
    if (right > 0 and left > 0):
        state = 5
        pass

    if (right > 0 and left <= 0):
        state = 3
        pass

    if (right <= 0 and left > 0):
        state = 1
        pass

    if (right <= 0 and left <= 0):
        state = 0
        pass


def enter_right():
    global right
    right = right + 1
    controller()


def enter_left():
    global left
    left += 1
    controller()


def exit_right():
    global right
    right -= 1
    controller()


def exit_left():
    global left
    left -= 1
    controller()
