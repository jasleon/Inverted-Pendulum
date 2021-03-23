import sys
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def generate_data():
    # Create base coordinates
    base_x = np.arange(-2., 2., 0.01)
    base_y = np.zeros_like(base_x)

    # Create pendulum's angle from the equilibrium position
    theta = np.arange(0., np.pi, np.pi / base_x.size)
    phi = np.pi / 2
    
    # Calculate pendulum coordinates
    rod_length = 0.75
    pendulum_x = base_x + rod_length * np.cos(theta + phi)
    pendulum_y = base_y + rod_length * np.sin(theta + phi)

    # Create an array with all the coordinates
    data = np.zeros((base_x.size, 4))
    data[:, 0] = base_x
    data[:, 1] = base_y
    data[:, 2] = pendulum_x
    data[:, 3] = pendulum_y

    return data

if __name__ == "__main__":
    for i, arg in enumerate(sys.argv):
        print('argv[{}]: {}'.format(i, arg))
    
    sim = generate_data()
    
    fig = plt.figure(figsize=(5, 4))
    ax = fig.add_subplot(111, autoscale_on=False, xlim=(-2, 2), ylim=(-1, 1))
    ax.set_aspect('equal')
    ax.grid()

    base, = ax.plot([],[],linestyle='None',marker='s',\
                 markersize=40,markeredgecolor='k',\
                 color='orange',markeredgewidth=2)
    pendulum, = ax.plot([],[],linestyle='None',marker='o',\
                 markersize=20,markeredgecolor='k',\
                 color='orange',markeredgewidth=2)
    rod, = ax.plot([],[],'o-',color='black',lw=4,\
                markersize=6,markeredgecolor='k',\
                markerfacecolor='k')
    
    def init():
        base.set_data([], [])
        pendulum.set_data([], [])
        rod.set_data([], [])
        return base, pendulum, rod
    
    def animate(i):
        # Unpack coordinates
        base_x = sim[i, 0]
        base_y = sim[i, 1]
        pendulum_x = sim[i, 2]
        pendulum_y = sim[i, 3]
        
        # Update visualization data
        base.set_data([base_x], [base_y])
        pendulum.set_data([pendulum_x], [pendulum_y])
        rod.set_data([base_x, pendulum_x], [base_y, pendulum_y])
        
        return base, pendulum, rod
    
    ani = animation.FuncAnimation(fig, animate, sim.shape[0], interval=10, repeat=True, blit=True)
    
    plt.show()