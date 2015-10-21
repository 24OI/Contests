type link = record
	val :longint;
	prev :longint;
	next :longint;
end;

var a :array[0..100007] of link;
	n,i,now,test,cs :longint;
	right :boolean;

begin
	assign(input,'eat.in');
	assign(output,'eat.out');
	reset(input);
	rewrite(output);
	
	read(n);
	for i := 1 to n do
	begin
		read(a[i].val);
		a[i].prev := i-1;
		a[i].next := i+1;
	end;

	cs := 0;
	repeat
		right := true;
		now := 1;
		if (a[a[1].next].val <> 0) then
		repeat
			test := a[now].next;
			if a[now].val > a[test].val then begin
				right := false;
                break;
			end
			else now := test;
		until a[a[now].next].val = 0;

		now := 1;
		test := a[1].next;
        if (a[test].val = 0) or (right = true) then break
        else inc(cs);
        repeat
			if a[a[test].prev].val > a[test].val then test := a[test].next
			else begin
				a[now].next := test;
				a[test].prev := now;
				now := test;
				test := a[now].next;
			end;
		until a[test].val = 0;
		a[now].next := n+1;
	until right = true;

	writeln(cs);
	
	close(input);
	close(output);
end.
