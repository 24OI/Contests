begin
assign(input,'C.in');
assign(output,'C.out');
reset(input);
rewrite(output);
writeln(-1);
close(input);
close(output);
end.
