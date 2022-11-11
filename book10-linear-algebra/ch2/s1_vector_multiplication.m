v = [1 2];
plot([0, v(1)], [0, v(2)])
hold on
for i=1:10
    s = randn;
    sv = s*v
    plot([0, sv(1)], [0, sv(2)])
end
grid on, axis(-4, 4, -4, 4)