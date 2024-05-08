`timescale 1ns/1ps
module barrelshifter32(
    input [31:0] Shift_Data,     // 32 位原始输入数据
    input [7:0] Shift_Num,      // 8 位输入数据，控制移位的位数
    input Carry_flag,           // CPSR 借/进位标志
    input [2:0] SHIFT_OP,   // 3 位输入控制移位的方式
    output wire [31:0] Shift_out,     // 32 位输出，由a 经过b 位通过aluc 指定的移位方式移位而得
    output reg Shift_carry_out      // 移位进位
);
    reg [63:0] temp;
    assign Shift_out[31:0] = temp[31:0];
    always@(Shift_Data or Shift_Num or Carry_flag or SHIFT_OP)begin
        case(SHIFT_OP[2:1])
            2'b00: begin
                if(Shift_Num[7:0] == 0)begin
                    temp[31:0] <= Shift_Data[31:0];
                end
                else if(Shift_Num[7:0] >= 1 && Shift_Num[7:0] <= 32) begin
                    temp[31:0] <= Shift_Data[31:0] << Shift_Num[7:0];
                    Shift_carry_out <= Shift_Data[32 - Shift_Num[7:0]];
                end
                else if(Shift_Num[7:0] > 32) begin
                    temp[31:0] <= 0;
                    Shift_carry_out <= 0;
                end
            end
            2'b01:begin
                if(SHIFT_OP[0] == 0 && Shift_Num[7:0] == 0)begin
                    temp[31:0] <= 0;
                    Shift_carry_out <= Shift_Data[31];
                end
                else if(SHIFT_OP[0] == 1 && Shift_Num[7:0] == 0)begin
                    temp[31:0] <= Shift_Data[31:0];
                end
                else if(Shift_Num[7:0] >= 1 && Shift_Num[7:0] <= 32)begin
                    temp[31:0] <= Shift_Data[31:0] >> Shift_Num[7:0];
                    Shift_carry_out <= Shift_Data[Shift_Num[7:0] - 1];
                end
                else if(Shift_Num[7:0] > 32)begin
                    temp[31:0] <= 0;
                    Shift_carry_out <= 0;
                end
            end
            2'b10:begin
                if(SHIFT_OP[0] == 0 && Shift_Num[7:0] == 0)begin
                    temp[31:0] <= {32{Shift_Data[31]}};
                    Shift_carry_out <= Shift_Data[31];
                end
                else if(SHIFT_OP[0] == 1 && Shift_Num[7:0] == 0)begin
                    temp[31:0] <= Shift_Data[31:0];
                end
                else if(Shift_Num[7:0] >= 1 && Shift_Num[7:0] <= 31)begin
                    temp[63:0] <= {{32{Shift_Data[31]}},Shift_Data[31:0]} >> Shift_Num[7:0];
                    Shift_carry_out <= Shift_Data[Shift_Num[7:0]-1];
                end
                else if(Shift_Num[7:0] >= 32)begin
                    temp[31:0] <= {32{Shift_Data[31]}};
                    Shift_carry_out <= Shift_Data[31];
                end
            end
            2'b11: begin
                if(SHIFT_OP[0] == 0 && Shift_Num[7:0] == 0) begin
                    temp[31:0] <= {Carry_flag,Shift_Data[31:1]};
                    Shift_carry_out <= Shift_Data[0];
                end
                else if(SHIFT_OP[0] == 1 && Shift_Num[7:0] == 0) begin
                    temp[31:0] <= Shift_Data[31:0];
                end
                else if(Shift_Num[7:0] >= 1) begin
                    temp[63:0] <= {Shift_Data[31:0],Shift_Data[31:0]} >> Shift_Num[4:0];
                    Shift_carry_out <= Shift_Data[Shift_Num[4:0] - 1];
                end
            end
        endcase
    end

endmodule
