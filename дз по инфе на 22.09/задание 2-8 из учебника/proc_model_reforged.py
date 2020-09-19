from proc_model_operations import *

# ТУТ ОСНОВНАЯ ПРОГА


class BAD_COMMAND(Exception):
    pass


class BAD_REGISTER(Exception):
    pass


def is_valid(s):
    if len(s) != 3:
        raise BAD_COMMAND()

    if s[0] not in '0123456789ABCD':
        raise BAD_COMMAND()

    if s[1] not in '0123':
        raise BAD_REGISTER()

    if s[1] == '1' and s[2] not in '0123456789A':
        raise BAD_COMMAND()

    elif s[2] not in '0123':
        raise BAD_REGISTER()

    return True


def do_help():
    print('Ну тут типа помощь должна всякая быть, но мне лень\nмы же не в продакшн прогу пишем\nВыход из программы - exit')


def do_op(s, R):
    command = s[0]
    if command == '1':
        OP1(s, R)
    elif command == '2':
        OP2(s, R)
    elif command == '3':
        OP3(s, R)
    elif command == '4':
        OP4(s, R)
    elif command == '5':
        OP5(s, R)
    elif command == '6':
        OP6(s, R)
    elif command == '7':
        OP7(s, R)
    elif command == '8':
        OP8(s, R)
    elif command == '9':
        OP9(s, R)
    elif command == 'A':
        OP10(s, R)
    return


R = [0, 0, 0, 0]
while True:
    try:
        print('Введите операцию из трех символов или help для получения помощи: ')
        s = input()
        if s == 'exit':
            print('The end')
            break
        if s == 'help':
            do_help()
            continue
        if is_valid(s):
            do_op(s, R)
            print('Registers : {}'.format(R))
        else:
            raise Exception()
    except BAD_REGISTER:
        print('Плохой регистр, давай все по новой!')
    except BAD_COMMAND:
        print('Плохая комманда, давай все по новой!')
    except ZeroDivisionError:
        print('ДЕЛИТЬ НА 0 НЕЛЬЗЯ, давай все по новой!')
