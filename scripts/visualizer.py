import sys
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def generate_mass1():
    x = np.arange(-2, 2, 0.01)
    y = np.zeros_like(x)
    return x, y

def generate_mass2(x_mass1, y_mass1):
    theta = np.arange(0, np.pi, np.pi / x_mass1.size)
    phi = 0.5 * np.pi
    x = x_mass1 + 0.5 * np.cos(theta + phi)
    y = y_mass1 + 0.5 * np.sin(theta + phi)
    return x, y

if __name__ == "__main__":
    for i, arg in enumerate(sys.argv):
        print('argv[{}]: {}'.format(i, arg))
    fig = plt.figure(figsize=(5, 4))
    ax = fig.add_subplot(111, autoscale_on=False, xlim=(-2, 2), ylim=(-1, 1))
    ax.set_aspect('equal')
    ax.grid()

    m1_x, m1_y = generate_mass1()
    m2_x, m2_y = generate_mass2(m1_x, m1_y)
    
    mass1, = ax.plot([],[],linestyle='None',marker='s',\
                 markersize=40,markeredgecolor='k',\
                 color='orange',markeredgewidth=2)
    mass2, = ax.plot([],[],linestyle='None',marker='o',\
                 markersize=20,markeredgecolor='k',\
                 color='orange',markeredgewidth=2)
    line, = ax.plot([],[],'o-',color='black',lw=4,\
                markersize=6,markeredgecolor='k',\
                markerfacecolor='k')
    
    def init():
        mass1.set_data([], [])
        mass2.set_data([], [])
        line.set_data([], [])
        return mass1, mass2, line
    
    def animate(i):
        mass1.set_data([m1_x[i]], [m1_y[i]])
        mass2.set_data([m2_x[i]], [m2_y[i]])
        line.set_data([m1_x[i], m2_x[i]], [m1_y[i], m2_y[i]])
        return mass1, mass2, line
    
    ani = animation.FuncAnimation(fig, animate, m1_x.size, interval=10, repeat=True, blit=True)
    
    plt.show()