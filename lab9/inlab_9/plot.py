import matplotlib.patches as mpatches
import matplotlib.pyplot as plt
import numpy as np

data = np.genfromtxt('data.csv', delimiter=',', names=['x', 'y', 'z'])
plt.plot(data['x'],data['z'],'g--', label='time taken')
plt.ylabel('time taken')
plt.xlabel('n')
plt.legend( loc='upper left', numpoints = 1 )
plt.show()
