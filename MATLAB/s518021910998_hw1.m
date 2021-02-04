function [BMI, status] = ComputeBMI(weight_lbs, height_foot, height_inch)
BMI=(weight_lbs/(height_foot*12+height_inch)^2)*703;
if BMI<18.5 
    status=1;
end
if (18.5<BMI)&&(BMI<24.9)
    status=2;
end
if (25.0<BMI)&&(BMI<29.9)
    status=3;
end
if BMI>30.0
    status=4;
end
BMI=round(BMI,1);
end

