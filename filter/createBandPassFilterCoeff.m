close all;
clear
clc
format long
Fstop1 = 0.6;   % First Stopband Frequency
Fpass1 = 0.61;  % First Passband Frequency
Fpass2 = 0.7;   % Second Passband Frequency
Fstop2 = 0.71;  % Second Stopband Frequency
Astop1 = 60;    % First Stopband Attenuation (dB)
Apass  = 1;     % Passband Ripple (dB)
Astop2 = 60;    % Second Stopband Attenuation (dB) 
h = fdesign.bandpass('fst1,fp1,fp2,fst2,ast1,ap,ast2', Fstop1, Fpass1, ...
Fpass2, Fstop2, Astop1, Apass, Astop2);   
Hd = design(h, 'equiripple','MinOrder', 'any');
coeff_bpf_struct=coeffs(Hd);
coeff_bpf=coeff_bpf_struct.Numerator;

fcoeff=fopen('bpf_coeff.txt','w');
for i=1:length(coeff_bpf)
    if i==length(coeff_bpf)
        fprintf(fcoeff,'%.8f',coeff_bpf(i));
    else
         fprintf(fcoeff,'%.8f\n',coeff_bpf(i));
    end
end
fclose(fcoeff);





