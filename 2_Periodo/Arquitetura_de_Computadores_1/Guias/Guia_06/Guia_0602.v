// ---------------------
// TRUTH TABLE 
// Nome: Vinicius Miranda de Araujo
// Matricula: 812839
// --------------------- 

// --------------------- 
// Expressoes
// --------------------- 

module g0602 (output s1,
            output s2,
            output s3,
            output s4,
            output s5,
            input  X, Y, Z); // MAXTERMOS
    assign s1 = (~Y|~Z) & (~X|~Z); 
    assign s2 = (~Y|Z) & (~X|Z); 
    assign s3 = (~Y|Z) & (Y|~Z);
    assign s4 = (X|~Y) & (~X|~Y);
    assign s5 = (X|~Y) & (~X|Y) ;
endmodule // g0602

// --------------------- 
// Guia_0602 
// --------------------- 

module Guia_0602; 
    reg   X = 0, Y = 0, Z = 0; 
    wire  s1, s2, s3, s4, s5; 
    integer i = 0; 
    // instancias 
    g0602 EXP (s1, s2, s3, s4, s5, X, Y, Z); 

    // valores iniciais 
    initial begin: start 
        X=1'bx; Y=1'bx; Z=1'bx;   // indefinidos 
    end // start

    // parte principal 
    initial begin: main 
        // identificacao 
        $display("Guia_0602 - Teste ");  
        
        // monitoramento 
        $display("\na.)");
        $display(" X  Y  Z = s1"); 
        $monitor("%2b %2b %2b = %2b", X, Y, Z, s1 ); 
        for (i = 0; i < 8; i = i + 1) begin
            { X, Y, Z } = i;
            #1;
        end // for

        $display("\nb.)");
        $display(" X  Y  Z = s2"); 
        $monitor("%2b %2b %2b = %2b", X, Y, Z, s2 ); 
        for (i = 0; i < 8; i = i + 1) begin
            { X, Y, Z } = i;
            #1;
        end // for

        $display("\nc.)");
        $display(" X  Y  Z = s3"); 
        $monitor("%2b %2b %2b = %2b", X, Y, Z, s3 ); 
        for (i = 0; i < 8; i = i + 1) begin
            { X, Y, Z } = i;
            #1;
        end // for

        $display("\nd.)");
        $display(" X  Y  Z = s4"); 
        $monitor("%2b %2b %2b = %2b", X, Y, Z, s4 );  
        for (i = 0; i < 8; i = i + 1) begin
            { X, Y, Z } = i;
            #1;
        end // for

        $display("\ne.)");
        $display(" X  Y  Z = s5"); 
        $monitor("%2b %2b %2b = %2b", X, Y, Z, s5 );  
        for (i = 0; i < 8; i = i + 1) begin
            { X, Y, Z } = i;
            #1;
        end // for
    end // main

endmodule // Guia_0602 