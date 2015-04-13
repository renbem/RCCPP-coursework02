function createVideo()

dir = 'Testing/ConwaysGameOfLifeData/';
filename = 'GameHistory.txt';

B = dlmread([dir filename]);

numberOfBoards = B(1,1);

B = B(2:end,:);