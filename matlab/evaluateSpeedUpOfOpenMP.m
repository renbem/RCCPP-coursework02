function evaluateSpeedUpOfOpenMP()

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
    
    foo = readComputationalTimeOfBoard(['GameHistory_' boardSizes{i} '_ComputationalTime_OpenMP.txt']);
    elapsedTime(i,2) = foo(end);
end

elapsedTime_200Times400_OpenMP = readComputationalTimeOfBoard('GameHistory_200Times400_ComputationalTime_OpenMP.txt');
elapsedTime_200Times400 = readComputationalTimeOfBoard('GameHistory_200Times400_ComputationalTime.txt');

elapsedTime_50Times100_OpenMP = readComputationalTimeOfBoard('GameHistory_50Times100_ComputationalTime_OpenMP.txt');
elapsedTime_50Times100 = readComputationalTimeOfBoard('GameHistory_50Times100_ComputationalTime.txt');

elapsedTime_10Times10_OpenMP = readComputationalTimeOfBoard('GameHistory_10Times10_ComputationalTime_OpenMP.txt');
elapsedTime_10Times10 = readComputationalTimeOfBoard('GameHistory_10Times10_ComputationalTime.txt');

%%

 
% set(0,'defaultTextFontSize', 20)
% set(0,'defaultAxesFontSize', 14)
% set(0,'DefaultLegendFontSize',22);
set(0, 'defaultTextInterpreter', 'latex');
set(0,'defaultaxesfontname','Times New Roman')

plotDir = 'figures/';
saveFlag = 1;

close all

MyLineWidth = 2;

figure
plot(1:numel(elapsedTime_200Times400),elapsedTime_200Times400, 'r-', 'LineWidth', MyLineWidth); hold on
plot(1:numel(elapsedTime_200Times400_OpenMP),elapsedTime_200Times400_OpenMP, 'r--', 'LineWidth', MyLineWidth); 
plot(1:numel(elapsedTime_50Times100),elapsedTime_50Times100, 'b-', 'LineWidth', MyLineWidth);
plot(1:numel(elapsedTime_50Times100_OpenMP),elapsedTime_50Times100_OpenMP, 'b--', 'LineWidth', MyLineWidth); 
plot(1:numel(elapsedTime_10Times10),elapsedTime_10Times10, 'g-', 'LineWidth', MyLineWidth); 
plot(1:numel(elapsedTime_10Times10_OpenMP),elapsedTime_10Times10_OpenMP, 'g--', 'LineWidth', MyLineWidth);
xlabel('Iterations')
ylabel('Computational Time [s]')
legend({...
    '$(200 \times 400)$-board (Serial)', '$(200 \times 400)$-board (OpenMP)'...
    '$(50 \times 100)$-board (Serial)', '$(50 \times 100)$-board (OpenMP)' ...
    '$(10 \times 10)$-board (Serial)', '$(10 \times 10)$-board (OpenMP)' ...
    },'interpreter','latex','Location','northwest')
legend boxoff
title('Serial and parallel computational time after 1000 steps')

if(saveFlag)
    print('-r600','-depsc2', [plotDir 'SerialOpenMP_Iterations.eps'])
end


figure
plot(boardCells,elapsedTime(:,1), 'rx', 'LineWidth', MyLineWidth); hold on
plot(boardCells,elapsedTime(:,2), 'bo', 'LineWidth', MyLineWidth);
legend('Serial','OpenMP','Location','northwest')
legend boxoff
xlabel('Number of Cells')
ylabel('Computational Time [s]')
title('Comparison of serial and parallel computational time after 1000 steps')

if(saveFlag)
    print('-r600','-depsc2', [plotDir 'SerialOpenMP_Cells.eps'])
end

figure
semilogx(boardCells,elapsedTime(:,1)./elapsedTime(:,2), 'rx', 'LineWidth', MyLineWidth); hold on
xlabel('Number of Cells')
ylabel('OpenMP/Serial')
title('Relative speed-up after 1000 steps')

if(saveFlag)
    print('-r600','-depsc2', [plotDir 'SerialOpenMP_Speedup.eps'])
end

end