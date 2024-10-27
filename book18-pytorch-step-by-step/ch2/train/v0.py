
N_EPOCHS = 1000
losses = []
for epoch in range(N_EPOCHS):
    loss = train_step_fn(x_train_tensor, y_train_tensor)
    losses.append(loss)
    if epoch % 100 == 0:
        print(f'Epoch: {epoch}, Loss: {loss:.4f}')
display(model.state_dict(), optimizer.state_dict())
