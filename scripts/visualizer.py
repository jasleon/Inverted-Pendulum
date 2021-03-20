import sys
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

if __name__ == "__main__":
    for i, arg in enumerate(sys.argv):
        print('argv[{}]: {}'.format(i, arg))
    fig = plt.figure(figsize=(5, 4))
    ax = fig.add_subplot(111, autoscale_on=False, xlim=(-2, 2), ylim=(-2, 1))
    ax.set_aspect('equal')
    ax.grid()

    x = np.arange(-2, 2, 0.01)
    mass, = ax.plot([],[],linestyle='None',marker='s',\
                 markersize=40,markeredgecolor='k',\
                 color='orange',markeredgewidth=2)
    
    def init():
        mass.set_data([], [])
        return mass,
    
    def animate(i):
        mass.set_data([x[i]], [0])
        return mass,
    
    ani = animation.FuncAnimation(fig, animate, x.size, interval=10, repeat=False, blit=True)
    
    plt.show()