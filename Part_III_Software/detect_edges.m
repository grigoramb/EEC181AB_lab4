% Team A+ Lab 4 EEC 181AB

clear;
clc;

% load the image
source = imread('lenna.jpg');

% convert to greyscale
grey_source = rgb2gray(source);


% Convert the image from unit8 to double for matrix multiplication
Org = double(grey_source);

height = size(Org,1); % get the number of rows
width = size(Org,2); % get the number of columns

% sobel matrices
Gx = [-1 0 1;-2 0 2; -1 0 1];
Gy = [1 2 1; 0 0 0; -1 -2 -1];

% skip first/last row/col
rows = 2:width-1;
cols = 2:height-1;

% result image
D = zeros(height,width);

for i = rows
    for j = cols
        block = Org(i-1:i+1,j-1:j+1);
        D(i,j) = (abs(sum(sum(Gx.*block))) + abs(sum(sum(Gy.*block)))) / 8;
    end
end

% convert back to uint
D = uint8(D);

% display result
figure;
imshow(D);

imwrite(D,'matlab_result.jpg');

