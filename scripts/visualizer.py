import sys

if __name__ == "__main__":
    for i, arg in enumerate(sys.argv):
        print('argv[{}]: {}'.format(i, arg))