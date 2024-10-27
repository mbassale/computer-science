
# Learning rate
lr = 0.1

# Model
model = nn.Sequential(nn.Linear(1, 1)).to(device)

# SGD Optimizer
optimizer = optim.SGD(model.parameters(), lr=lr)

# MSE Loss
loss_fn = nn.MSELoss(reduction='mean')

# Train Step Function
train_step_fn = make_train_step_fn(model, loss_fn, optimizer)

display(model.state_dict(), optimizer.state_dict())
