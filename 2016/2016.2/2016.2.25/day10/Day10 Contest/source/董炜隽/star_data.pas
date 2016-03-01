const
  n=1000;
var
  i,x:longint;

begin
  randomize;
  assign(output,'star.in');
  rewrite(output);
  writeln(n);
  for i:=1 to n do
    writeln(random(2001)-1000,' ',random(2001)-1000,' ',random(200000001)-100000000);
end.
