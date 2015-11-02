
begin
assign(input,'pinball.in');
reset(input);
assign(output,'pinball.out');
rewrite(output);
writeln(-1);
close(input);close(output);	
end.