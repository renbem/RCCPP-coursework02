function generateInitialBoard()

rows = 40;
columns = 60;

A = rand(rows,columns)>0.9;

dir = 'Testing/ConwaysGameOfLifeData/';
filename = 'InitialBoardRandom.txt';

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

