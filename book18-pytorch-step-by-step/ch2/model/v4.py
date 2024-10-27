
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

# Validation Step Function
validation_step_fn = make_validation_step_fn(model, loss_fn)

writer = SummaryWriter('runs/linear_regression')

display(model.state_dict(), optimizer.state_dict())

USE_CHECKPOINT = False
start_epoch = 0
if USE_CHECKPOINT:
    checkpoint = torch.load('checkpoint.pth')
    model.load_state_dict(checkpoint['model_state_dict'])
    optimizer.load_state_dict(checkpoint['optimizer_state_dict'])
    start_epoch = checkpoint['epoch']
    loss = checkpoint['loss']
    display('Loaded model from checkpoint')
