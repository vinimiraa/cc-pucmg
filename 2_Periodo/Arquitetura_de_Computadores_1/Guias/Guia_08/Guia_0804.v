// ------------------------- 
// Guia_0804 - INEQUALITY COMPARATOR
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

// ------------------------- 
// inequality comparator 
// ------------------------- 
module isDiff ( output s, input a, input b ); 
    // descrever por portas 
    xor XOR0 ( s, a, b ); 
endmodule // isDiff 

// ------------------------- 
//  Guia_0804 
// ------------------------- 
module Guia_0804; 
    // ------------------------- definir dados 
    reg  [5:0] x; // input1
    reg  [5:0] y; // input2

    reg  [5:0] a; // input3
    reg  [5:0] b; // input4

    wire [5:0] s1; // output1
    wire [5:0] s2; // output2
    
    // Instancias de s1, x, y
    isDiff XY0 ( s1[0], x[0], y[0] );
    isDiff XY1 ( s1[1], x[1], y[1] );
    isDiff XY2 ( s1[2], x[2], y[2] );
    isDiff XY3 ( s1[3], x[3], y[3] );
    isDiff XY4 ( s1[4], x[4], y[4] );
    isDiff XY5 ( s1[5], x[5], y[5] );
    // Instancias de s2, a, b
    isDiff AB0 ( s2[0], a[0], b[0] );
    isDiff AB1 ( s2[1], a[1], b[1] );
    isDiff AB2 ( s2[2], a[2], b[2] );
    isDiff AB3 ( s2[3], a[3], b[3] );
    isDiff AB4 ( s2[4], a[4], b[4] );
    isDiff AB5 ( s2[5], a[5], b[5] );

    // Atribuindo valores
    initial begin : start
        // valores iguais para 'x' e 'y'
        x = 6'b101_010;
        y = 6'b101_010;
        // valores diferentes para 'a' e 'b'
        a = 6'b100_111;
        b = 6'b100_100;
    end // start

    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0804 - Vinicius Miranda de Araujo - 812839"); 
        $display("Test ALU’s equality comparator"); 

        #1;
        // Teste de desigualdade entre x e y
        $write( "%b  ==  %b ? %b = ", x, y, s1 );
		if( s1 == 6'b000000 ) begin
			$display( "true" );
		end // if
		else begin
			$display( "false" );
		end // else

        #1;
        // Teste de desigualdade entre a e b
        $write( "%b  ==  %b ? %b = ", a, b, s2 );
		if( s2 == 6'b000000 ) begin
			$display( "true" );
		end // if
		else begin
			$display( "false" );
		end // else
    end // main
endmodule // Guia_0804 