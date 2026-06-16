// ----------------
// --- Moore_1010
// ----------------
module Moore_1010 (
    output reg y, // Saída indicando se a sequência foi encontrada
    input x,      // Entrada de dados (0 ou 1)
    input clk,    // Sinal de clock
    input reset   // Sinal de reset
);

    // Constantes
    parameter start  = 3'b000;
    parameter id1    = 3'b001;
    parameter id11   = 3'b011;
    parameter id110  = 3'b010;
    parameter id1101 = 3'b110;

    // Variáveis de estado
    reg [2:0] E1, 
    reg [2:0] E2;

    // Lógica da máquina de estados
    always @( posedge clk or negedge reset ) begin
        if ( reset == 1'b0 ) begin
            E1 <= start;
            y <= 1'b0;
        end else begin
            E1 <= E2;
            case( E1 )
                start: begin
                    if ( x == 1'b1 ) begin
                        E2 = id1;
                    end else begin
                        E2 = start;
                    end
                end
                id1: begin
                    if ( x == 1'b0 ) begin
                        E2 = id11;
                    end else begin
                        E2 = start;
                    end
                end
                id11: begin
                    if ( x == 1'b1 ) begin
                        E2 = id110;
                    end else begin
                        E2 = start;
                    end
                end
                id110: begin
                    if ( x == 1'b0 ) begin
                        E2 = id1101;
                    end else begin
                        E2 = start;
                    end
                end
                id1101: begin
                    if ( x == 1'b0 ) begin
                        E2 = id11;
                    end else begin
                        E2 = start;
                    end
                end
                default: begin
                    E2 = start;
                end
            endcase
        end
    end

    // Lógica de saída
    always @( E1 ) begin
        if ( E1 == id1101 ) begin
            y = 1'b1; // Sequência encontrada
        end else begin
            y = 1'b0; // Sequência interrompida
        end
    end
endmodule // Moore_1010

// ----------------
// --- Teste
// ----------------
module Guia_1103; 
    reg   clk, reset, x; 
    wire  m1; 

    Moore_1010 mealy1 ( m1, x, clk, reset ); 

    initial begin
    $display ( "Time     X   Mealy" ); 
        // initial values 
        clk   = 1; 
        reset = 0; 
        x     = 0; 

        // input signal changing 
        #5   reset = 1; 
        #10  x = 1; 
        #10  x = 0; 
        #10  x = 1; 
        #20  x = 0; 
        #10  x = 1; 
        #10  x = 1; 
        #10  x = 0; 
        #10  x = 1; 

        #30 $finish; 
    end // initial 

    always 
        #5 clk = ~clk; 

    always @( posedge clk ) begin 
        $display ( "%4d  %4b  %4b", $time, x, m1 ); 
    end // always at positive edge clocking changing 

endmodule // Guia_1103