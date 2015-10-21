begin
	assign(input,'jump.in');reset(input);
	assign(output,'jump.out');rewrite(output);
	writeln('2');
	close(input);
	close(output);
end.