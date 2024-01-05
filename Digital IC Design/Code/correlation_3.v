module correlation_3 ( y, clock, reset, x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, h_0, h_1, h_2, h_3, h_4, h_5, h_6, h_7, h_8, h_9);

  output reg [11:0] y;

  input clock, reset;

  input [3:0] x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9;
  input [3:0] h_0, h_1, h_2, h_3, h_4, h_5, h_6, h_7, h_8, h_9;

  reg [2:0] counter;

  reg [3:0] mul_even_x, mul_even_h, mul_odd_x, mul_odd_h;
  reg [7:0] mul_even, mul_odd;

  reg [11:0] memory_sum;

  initial 
  begin

    counter <= 3'b000;
    mul_even_x <= 4'b0000;
    mul_even_h <= 4'b0000;
    mul_odd_x <= 4'b0000;
    mul_odd_h <= 4'b0000;
    mul_even <= 8'b0000_0000;
    mul_odd <= 8'b0000_0000;
    memory_sum <= 12'b0000_0000_0000;
    y <= 12'b0000_0000_0000;

  end

  always @(posedge clock) 
  begin

    if (counter < 6) 
    begin
      counter <= counter + 1;
    end 
    
    else 
    begin
      counter <= 3'b111;
    end

  end

  always @(x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9)
  begin 

    counter <= 3'b000;
    y <= 12'b0000_0000_0000;

  end   

  always @(counter) 
  begin

    case (counter)

      3'b000: 
      begin
      
        mul_even_x <= x_0;
        mul_even_h <= h_0;
        mul_odd_x  <= x_1;
        mul_odd_h  <= h_1;
      
      end

      3'b001: 
      begin
      
        mul_even_x <= x_2;
        mul_even_h <= h_2;
        mul_odd_x  <= x_3;
        mul_odd_h  <= h_3;
      
      end

      3'b010: 
      begin
      
        mul_even_x <= x_4;
        mul_even_h <= h_4;
        mul_odd_x  <= x_5;
        mul_odd_h  <= h_5;
      
      end

      3'b011: 
      begin
      
        mul_even_x <= x_6;
        mul_even_h <= h_6;
        mul_odd_x  <= x_7;
        mul_odd_h  <= h_7;
      
      end

      3'b100: 
      begin
      
        mul_even_x <= x_8;
        mul_even_h <= h_8;
        mul_odd_x  <= x_9;
        mul_odd_h  <= h_9;
      
      end

      default:
      begin 

        mul_even_x <= 4'b0000;
        mul_even_h <= 4'b0000;
        mul_odd_x  <= 4'b0000;
        mul_odd_h  <= 4'b0000;
      
      end 

    endcase

    mul_even <= mul_even_x * mul_even_h;
    mul_odd <= mul_odd_x * mul_odd_h;
    memory_sum <= mul_even + mul_odd;

  end

  always @(negedge clock) 
  begin

	  y <= (y + memory_sum);

  end

endmodule
