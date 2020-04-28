clc;
clear all;

addpath("F:\Assign\Diffusion\diffusion");
a=importdata('data5.dat');
b=importdata('data20.dat');
c=importdata('data50.dat');
d=importdata('data7200.dat');


%Removing repeated column
a(:,2)=[];
b(:,2)=[];
c(:,2)=[];
d(:,2)=[];

%Plot
figure(1)
imagesc(a);
set(gca,'FontSize',12);
title("Temperature Contour plot in K at t =5 s");
colorbar('eastoutside');
print('-dpng','-r500','5s.png');

figure(2)
imagesc(b);
set(gca,'FontSize',12);
title("Temperature Contour plot in K at t =20 s");
colorbar('eastoutside');
print('-dpng','-r500','20s.png');

figure(3)
imagesc(c);
set(gca,'FontSize',12);
title("Temperature Contour plot in K at t =50 s");
colorbar('eastoutside');
print('-dpng','-r500','50s.png');

figure(4)
imagesc(d);
set(gca,'FontSize',12);
title("Temperature Contour plot in K at t =7200 s");
colorbar('eastoutside');
print('-dpng','-r500','7200s.png');



    