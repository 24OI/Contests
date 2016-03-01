const
  n=100000;
  m=100000;
var
  i,x,y,t:longint;

begin
  randomize;
  assign(output,'fibnacci.in');
  rewrite(output);
  writeln(n,' ',m);
  for i:=1 to n do
    write(random(1000000010),' ');
  writeln;
  for i:=1 to m do
    begin
      x:=random(n)+1;
      y:=random(n)+1;
      if x>y then
        begin
          t:=x;
          x:=y;
          y:=t;
        end;
      writeln(random(2)+1,' ',x,' ',y);
    end;
end.