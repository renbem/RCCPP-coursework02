function generateInitialBoard()

dir = 'Testing/ConwaysGameOfLifeData/';

rows = 40;
columns = 60;

A = rand(rows,columns)>0.9;
filename = 'InitialBoardRandom.txt';

%***Generate numbered board for unit test: 
% A = zeros(rows,columns); A(:) = 0:rows*columns-1;
% filename = 'TestBoardNumbered.txt';

f = fopen([dir filename],'w');

for i=1:rows
    for j=1:columns
        fprintf(f,'%d', A(i,j));
        if(j~=columns)
            fprintf(f,'\t');
        end
    end
    if(i~=rows)
        fprintf(f,'\n');
    end
end
fclose(f);
end

