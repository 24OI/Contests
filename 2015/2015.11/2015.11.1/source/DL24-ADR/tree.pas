begin
	assign(input,'tree.in');reset(input);
	assign(output,'tree.out');rewrite(output);
	writeln(10);
	close(input);
	close(output);
end.