import matplotlib
matplotlib.use('Agg')
import numpy as np
import matplotlib.pyplot as plt
delta_x=0.05;
L = 4.0
N = int(L/delta_x + 1)
data=np.loadtxt("advecc_para.txt")
data_serie=np.loadtxt("advecc_ser.txt")
plt.plot(data[0:81,1],data[0:81,0],label="iniciales_para")
plt.plot(data[(N+1):2*(N+1),1],data[1*(N+1):2*(N+1),0], label="finales_para")
plt.plot(data_serie[0:81,1],data[0:81,0],label="iniciales_serie")
plt.plot(data_serie[1*(N+1):2*(N+1),1],data[1*(N+1):2*(N+1),0], label="finales_serie")
plt.legend()
plt.ylim((0.0,1.2))
plt.savefig("adveccion.pdf")
