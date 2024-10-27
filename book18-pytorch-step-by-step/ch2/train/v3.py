
N_EPOCHS = 200
losses = []
for epoch in range(N_EPOCHS):
    loss = mini_batch(device, train_loader, train_step_fn)
    losses.append(loss)
    if epoch % 10 == 0:
        print(f'Epoch: {epoch}, Loss: {loss:.4f}')
display(model.state_dict(), optimizer.state_dict())
