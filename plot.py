import numpy as np
import matplotlib.pyplot as plt


def load_data(filename):
    file_handler=open(filename,"r")
    lines=file_handler.readlines()
    file_handler.close()
    data=np.array([])
    for line in lines:
        data=np.append(data,float(line))
    return data

# Load data from file generated by main.c
filterednoise=load_data("datas/filterednoise.txt")
unfilterednoise=load_data("datas/unfilterednoise.txt")

# Take fft of both noise
fft_filterednoise=abs(np.fft.fft(filterednoise))
fft_unfilterednoise=abs(np.fft.fft(unfilterednoise))
fft_unfilterednoise[0]=fft_unfilterednoise.mean()   #to better see frequency content of unfiltered noise

# Normalize the Frequency Content of filtered noise
norm_freq_filterednoise=np.linspace(0,1,int(len(fft_filterednoise)/2))
norm_fft_filterednoise=fft_filterednoise[0:int(len(fft_filterednoise)/2)]

# Normalize the Frequency Content of unfiltered noise
norm_freq_unfilterednoise=np.linspace(0,1,int(len(fft_unfilterednoise)/2))
norm_fft_unfilterednoise=fft_unfilterednoise[0:int(len(fft_unfilterednoise)/2)]

plt.subplot(211)
plt.xlabel("Normalized Frequency Content\n of unfiltered noise")
plt.ylabel("Fast Fourier transform of \nunfiltered noise")
plt.plot(norm_freq_unfilterednoise,norm_fft_unfilterednoise)
plt.subplot(212)
plt.xlabel("Normalized Frequency Content\n of filtered noise")
plt.ylabel("Fast Fourier transform of \nfiltered noise")
plt.plot(norm_freq_filterednoise,norm_fft_filterednoise)
plt.show()