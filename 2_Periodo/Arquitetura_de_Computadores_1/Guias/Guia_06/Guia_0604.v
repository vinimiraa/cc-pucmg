// ---------------------
// TRUTH TABLE 
// Nome: Vinicius Miranda de Araujo
// Matricula: 812839
// --------------------- 

// --------------------- 
// Expressoes
// --------------------- 

module g0604 (output s1,
            output s2,
            output s3,
            output s4,
            output s5,
            input  X, Y, W, Z); // MAXTERMOS 
    assign s1 = (~Y|W|~Z) & (X|~Y|~Z) & (X|Y|~W|Z); 
    assign s2 = (X|~Y|Z) & (~Y|~W|Z) & (~X|Y|~Z); 
    assign s3 = (X|~Y|W|Z) & (~X|~Y|~Z) & (~X|Y|W);
    assign s4 = (X|W|~Z) & (~Y|~Z) & (~X|~Y|~W);
    assign s5 = (X|~W|~Z) & (~Y|~Z) & (~Y|~W|Z);
endmodule // g0604

// --------------------- 
// Guia_0604 
// --------------------- 

module Guia_0604; 
    reg   X = 0, Y = 0, W = 0, Z = 0; 
    wire  s1, s2, s3, s4, s5; 
    integer i = 0; 
    // instancias 
    g0604 EXP (s1, s2, s3, s4, s5, X, Y, W, Z); 

    // valores iniciais 
    initial begin: start 
        X=1'bx; Y=1'bx; W=1'bx; Z=1'bx;   // indefinidos 
    end // start

    // parte principal 
    initial begin: main 
        // identificacao 
        $display("Guia_0604 - Teste ");  
        
        // monitoramento 
        $display("\na.)");
        $display(" X  Y  W  Z = s1"); 
        $monitor("%2b %2b %2b %2b = %2b", X, Y, W, Z, s1 ); 
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // for

        $display("\nb.)");
        $display(" X  Y  W  Z = s2"); 
        $monitor("%2b %2b %2b %2b = %2b", X, Y, W, Z, s2 ); 
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // for

        $display("\nc.)");
        $display(" X  Y  W  Z = s3"); 
        $monitor("%2b %2b %2b %2b = %2b", X, Y, W, Z, s3 ); 
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // for

        $display("\nd.)");
        $display(" X  Y  W  Z = s4"); 
        $monitor("%2b %2b %2b %2b = %2b", X, Y, W, Z, s4 );  
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // for

        $display("\ne.)");
        $display(" X  Y  W  Z = s5"); 
        $monitor("%2b %2b %2b %2b = %2b", X, Y, W, Z, s5 );  
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // for
    end // main

endmodule // Guia_0604 