// -------------- 
// --- Moore FSM 
// -------------- 

/* 
                Moore FSM Diagram 
                             ___________________ 
                            /                    \ 
           1         1      v     0          1   1| // found 
   [start] ---> [id1] ---> [id11] --->> [id110] ---> [id1101] 
     ^  \0      0 |       1^  \        0 |       0| 
      \_/        /         \__/          |        | 
       \________/                        |        | 
        \                                |        | 
         \_______________________________/        | 
          \                                       | 
           \______________________________________/ 
*/ 

// constant definition 
`define found      1 
`define notfound 0 

// FSM by Moore 
module Moore_1101 ( y, x, clk, reset ); 
    output y; 
    input  x; 
    input  clk; 
    input  reset; 

    reg y; 

    parameter // state identifiers 
    start  = 3'b000, 
    id1    = 3'b001, 
    id11   = 3'b011, 
    id110  = 3'b010, 
    id1101 = 3'b110; // signal found 

    reg [2:0] E1; // current state variables 
    reg [2:0] E2; // next state logic output 

    // next state logic 
    always @( x or E1 ) begin 
        case( E1 ) 
        start: 
            if ( x ) 
                E2 = id1; 
            else 
                E2 = start; 
        id1: 
            if ( x ) 
                E2 = id11; 
            else 
                E2 = start; 
        id11: 
            if ( x ) 
                E2 = id11; 
            else 
                E2 = id110; 
        id110: 
            if ( x ) 
                E2 = id1101; 
            else 
                E2 = start; 
        id1101: 
            if ( x ) 
                E2 = id11; 
            else 
                E2 = start; 
            default:   // undefined state 
                E2 = 3'bxxx; 
        endcase 
    end // always at signal or state changing 

    // state variables 
    always @( posedge clk or negedge reset ) begin 
        if ( reset ) 
            E1 = E2; // updates current state 
        else 
            E1 = 0;  // reset 
    end // always at signal changing 

    // output logic 
    always @( E1 ) begin 
        y = E1[2];   // first bit of state value (MOORE indicator) 
    end // always at state changing 

endmodule // Moore_1101