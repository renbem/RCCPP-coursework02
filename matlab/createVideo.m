function createVideo()

dir = '../test/data/';
filename = 'GameHistory_200Times400.txt';

B = dlmread([dir filename]);

numberOfBoards = B(1,1);

B = B(2:end,:);
B = mod(B+1,2);     %invert colours of black and white

rows = size(B,1)/numberOfBoards;
columns = size(B,2);

outputVideo = VideoWriter('../ConwaysGameOfLife.avi');
outputVideo.FrameRate = 10;
outputVideo.Quality = 100;
% outputVideo.Height = columns*scale;
% outputVideo.Width = rows*scale;
open(outputVideo);

% figure
% imagesc(1:rows, :);

for j = 1:numberOfBoards
    fig=imagesc(B((j-1)*rows+1 : j*rows, :)); 
    colormap(gray);
    
    frame = getframe(gcf);  % Capture figure's content
    writeVideo(outputVideo,frame.cdata); % The actual pixel values are in 'cdata'.
%     pause(0.2) % Just used to see the actual movie 
end

close(gcf);
close(outputVideo);

