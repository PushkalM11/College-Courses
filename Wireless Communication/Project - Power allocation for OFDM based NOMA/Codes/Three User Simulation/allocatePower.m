function [alpha1, beta2, beta3, alpha4] = allocatePower(h1, h2, h3, h4, method, N_monte_carlo)
        
    if strcmp(method, 'equal')
        
        alpha1 = 0.25 .* ones(1, N_monte_carlo);
        beta2 = 0.25 .* ones(1, N_monte_carlo); 
        beta3 = 0.25 .* ones(1, N_monte_carlo);
        alpha4 = 0.25 .* ones(1, N_monte_carlo);
        
    end
    
    if strcmp(method, 'manual')
        
        alpha1 = 0.1 .* ones(1, N_monte_carlo);
        beta2 = 0.2 .* ones(1, N_monte_carlo); 
        beta3 = 0.29 .* ones(1, N_monte_carlo);
        alpha4 = 0.41 .* ones(1, N_monte_carlo);
        
    end
    
    if strcmp(method, 'water_filling')
        
        alpha1 = zeros(1, N_monte_carlo);
        beta2 = zeros(1, N_monte_carlo);
        beta3 = zeros(1, N_monte_carlo);
        alpha4 = zeros(1, N_monte_carlo);
        
        for i = 1 : N_monte_carlo
            
            c = (1 / h1(i)) + (1 / h2(i)) + (1 / h3(i)) + (1 / h4(i));
            alpha1(i) = c - (1 / h1(i));
            beta2(i) = c - (1 / h2(i));
            beta3(i) = c - (1 / h3(i));
            alpha4(i) = c - (1 / h4(i));
            
        end
        
    end

end