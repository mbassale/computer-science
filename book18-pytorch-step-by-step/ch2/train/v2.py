
N_EPOCHS = 1000
losses = []
for epoch in range(N_EPOCHS):

    mini_batch_losses = []
    for x_batch, y_batch in train_loader:
        x_batch = x_batch.to(device)
        y_batch = y_batch.to(device)
        loss = train_step_fn(x_batch, y_batch)
        mini_batch_losses.append(loss)
    
    # Compute mean loss for the epoch
    loss = np.mean(mini_batch_losses)
    losses.append(loss)
    if epoch % 100 == 0:
        print(f'Epoch: {epoch}, Loss: {loss:.4f}')
display(model.state_dict(), optimizer.state_dict())
