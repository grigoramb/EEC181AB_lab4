clear;clc;

inputname = 'lenna.jpg';

source = imread(inputname);
width = size(source,2);
height = size(source,1);

% convert to greyscale
grey_source = rgb2gray(source);

fid = fopen('greyscale.txt','wt');
fwrite(fid,grey_source');
fclose(fid);

system('gcc detect_edges_new.c -o detect_edges.out');
command = sprintf('./detect_edges.out greyscale.txt c_output.txt %d %d',width,height);
system(command);

fid2 = fopen('c_output.txt','r');

a = fread(fid2,height*width);
fclose(fid2);
b = vec2mat(a,width);
c = uint8(b);

imshow(c);
imwrite(c,'c_result.jpg');

delete c_output.txt;
delete greyscale.txt;