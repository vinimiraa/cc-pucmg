// ------------------------------
// --- Guia_12
// Autor: Vinícius Miranda de Araújo Matrícula: 812839
// -----------------------------

// `include "ram1x4.v"
// `include "ram1x8.v"
`include "ram2x8.v"

module Guia_12;
    // variaveis
    reg  address1, address2, rw, clock, clear;      // variaveis de controle
    reg  i1, i2, i3, i4, i5, i6, i7, i8; // input
    wire o1, o2, o3, o4, o5, o6, o7, o8; // output

    // instancia 
    ram1x4 RAM_1x4_1 ( o1, o2, o3, o4, 
                    address1, rw, clock, clear,
                    i1, i2, i3, i4 );

    ram1x8 RAM1x8_1 ( o1, o2, o3, o4, o5, o6, o7, o8, 
                    address1, rw, clock, clear,
                    i1, i2, i3, i4, i5, i6, i7, i8 );

    ram2x8 RAM2x8_1 ( o1, o2, o3, o4, o5, o6, o7, o8,
                    address1, rw, clock, clear,
                    i1, i2, i3, i4, i5, i6, i7, i8 );

    initial begin: main 
        $display ( "Guia_12.v - Teste" );
        $display ( "  clock    rw    address    input    output");
        // initial values
        clock    = 1;
        rw       = 0;
        address1 = 0;
        address2 = 0;
        clear    = 1;
        i1 = 0; i2 = 0; i3 = 0; i4 = 0; i5 = 0; i6 = 0; i7 = 0; i8 = 0;
        // input signal
        #5 clear = 0;
        #10 rw = 1; address1 = 0; address2 = 0; i1 = 0; i2 = 0; i3 = 0; i4 = 0; i5 = 0; i6 = 0; i7 = 1; i8 = 1;
        #10 rw = 1; address1 = 0; address2 = 1; i1 = 0; i2 = 0; i3 = 0; i4 = 0; i5 = 1; i6 = 1; i7 = 0; i8 = 0;
        #10 rw = 1; address1 = 1; address2 = 0; i1 = 0; i2 = 0; i3 = 1; i4 = 1; i5 = 0; i6 = 0; i7 = 0; i8 = 0;
        #10 rw = 1; address1 = 1; address2 = 1; i1 = 1; i2 = 1; i3 = 0; i4 = 0; i5 = 0; i6 = 0; i7 = 0; i8 = 0;
        #10 rw = 0; address1 = 0; address2 = 0; i1 = 0; i2 = 0; i3 = 0; i4 = 0; i5 = 0; i6 = 0; i7 = 0; i8 = 0;
        #10 rw = 0; address1 = 0; address2 = 1; i1 = 0; i2 = 0; i3 = 0; i4 = 0; i5 = 0; i6 = 0; i7 = 0; i8 = 0;
        #10 rw = 0; address1 = 1; address2 = 0; i1 = 0; i2 = 0; i3 = 0; i4 = 0; i5 = 0; i6 = 0; i7 = 0; i8 = 0;
        #10 rw = 0; address1 = 1; address2 = 1; i1 = 0; i2 = 0; i3 = 0; i4 = 0; i5 = 0; i6 = 0; i7 = 0; i8 = 0;
        #10 
        $finish;
    end // main
    
    always 
        #3 clock = ~clock;

    always @( posedge clock ) begin
        $display ( " %4d    %4d    %4d    %5d%d%d%d    %3d%d%d%d", $time, rw, address1, i1, i2, i3, i4, o1, o2, o3, o4);
    end // always at positive edge clocking changing

endmodule // Guia_12
