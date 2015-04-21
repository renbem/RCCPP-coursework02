function evaluateSpeedUpOfMPI()

boardSizes = {...
    '10Times10'...
    '10Times20'...
    '10Times50'...
    '10Times100'...
    '50Times100'...
    '100Times100'...
    '100Times200'...
    '200Times200'...
    '200Times300'...
    '200Times400'...
    };

boardCells = [...
    100
    200
    500
    1e3
    5e3
    10e3
    20e3
    40e3
    60e3
    80e3];

N = numel(boardCells);

if(N ~= numel(boardSizes))
    error('revise sizes');
end

elapsedTime = zeros(N,2);

for i=1:N
    disp(boardSizes{i})
    foo = readComputationalTimeOfBoard(['GameHistory_' boardSizes{i} '_ComputationalTime.txt']);
    elapsedTime(i,1) = foo(end);
    
    foo = readComputationalTimeOfBoard(['GameHistory_' boardSizes{i} '_ComputationalTime_MPI.txt']);
    elapsedTime(i,2) = foo(end);
end

elapsedTime_200Times400_MPI = readComputationalTimeOfBoard('GameHistory_200Times400_ComputationalTime_MPI.txt');
elapsedTime_200Times400 = readComputationalTimeOfBoard('GameHistory_200Times400_ComputationalTime.txt');

elapsedTime_50Times100_MPI = readComputationalTimeOfBoard('GameHistory_50Times100_ComputationalTime_MPI.txt');
elapsedTime_50Times100 = readComputationalTimeOfBoard('GameHistory_50Times100_ComputationalTime.txt');

elapsedTime_10Times10_MPI = readComputationalTimeOfBoard('GameHistory_10Times10_ComputationalTime_MPI.txt');
elapsedTime_10Times10 = readComputationalTimeOfBoard('GameHistory_10Times10_ComputationalTime.txt');


close all

MyLineWidth = 2;

figure
plot(1:numel(elapsedTime_200Times400_MPI),elapsedTime_200Times400_MPI, 'r-', 'LineWidth', MyLineWidth); hold on
plot(1:numel(elapsedTime_200Times400),elapsedTime_200Times400, 'r--', 'LineWidth', MyLineWidth);
plot(1:numel(elapsedTime_50Times100_MPI),elapsedTime_50Times100_MPI, 'b-', 'LineWidth', MyLineWidth); hold on
plot(1:numel(elapsedTime_50Times100),elapsedTime_50Times100, 'b--', 'LineWidth', MyLineWidth);
plot(1:numel(elapsedTime_10Times10_MPI),elapsedTime_10Times10_MPI, 'g-', 'LineWidth', MyLineWidth); hold on
plot(1:numel(elapsedTime_10Times10),elapsedTime_10Times10, 'g--', 'LineWidth', MyLineWidth);
xlabel('Iterations')
ylabel('Computational Time [s]')
title('Comparison of three boards')

figure
semilogx(boardCells,elapsedTime(:,1), 'rx', 'LineWidth', MyLineWidth); hold on
semilogx(boardCells,elapsedTime(:,2), 'bo', 'LineWidth', MyLineWidth);
xlabel('Number of Cells')
ylabel('Computational Time [s]')

figure
semilogx(boardCells,elapsedTime(:,1)./elapsedTime(:,2), 'rx', 'LineWidth', MyLineWidth); hold on
xlabel('Number of Cells')
ylabel('MPI/Serial')

end