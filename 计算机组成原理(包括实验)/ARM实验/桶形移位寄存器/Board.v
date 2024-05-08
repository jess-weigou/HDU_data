`timescale 1ns / 1ps
module Board(sw, swb, led, clk, which, seg, enable);
    input [1:32] sw;
    output [1:32] led;
    input clk; 
    input [1:6] swb;
    output [2:0] which;
    output [7:0] seg;
    output reg enable = 1; 

//    barrelshifter
   reg [31:0] Shift_Data;
   reg [7:0] Shift_Num;
   reg Carry_flag;
   reg [2:0] SHIFT_OP;
   wire [31:0] datatube; 
   barrelshifter32 BB1(
       .Shift_Data(Shift_Data),
       .Shift_Num(Shift_Num),
       .Carry_flag(Carry_flag),
       .SHIFT_OP(SHIFT_OP),
       .Shift_out(datatube),
       .Shift_carry_out(led[1])
   );
   always@(posedge clk)begin
       if(swb[1] == 1'b1)begin
           Shift_Data[31:0] <= sw[1:32];
       end
       if(swb[2] == 1'b1)begin
           SHIFT_OP[2:0] <= sw[1:3];
           Shift_Num [7:0]<= sw[9:16];
       end
       if(swb[4] == 1'b1)begin
           SHIFT_OP <= 0;
           Shift_Num <= 0;
           Shift_Data <= 0; 
        end 
   end
   always@(swb[3])begin
           Carry_flag <= swb[3];
   end
   Display Display_Instance(.clk(clk), .data(datatube),
       .which(which), .seg(seg));


endmodule //
