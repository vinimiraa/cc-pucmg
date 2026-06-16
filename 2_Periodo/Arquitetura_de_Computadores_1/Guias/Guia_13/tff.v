// -----------------------
// --- Flip-Flop tipo T
// Autor: Vinícius Miranda de Araújo Matrícula: 812839
// -----------------------
module tff (output q, output qnot, input t, input clk, input preset, input clear ); 
    reg q, qnot; 

    always @( posedge clk or ~preset or ~clear ) begin 
        if ( ~clear ) 
            begin q <= 0;  qnot <= 1; end 
        else if ( ~preset ) 
            begin q <= 1;  qnot <= 0; end 
        else 
            begin if ( t ) begin  q <= ~q; qnot <= ~qnot; end end 
    end 
endmodule // tff