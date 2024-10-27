
N_EPOCHS = 200
losses = []
validation_losses = []
for epoch in range(start_epoch, N_EPOCHS):
    loss = mini_batch(device, train_loader, train_step_fn)
    losses.append(loss)
    
    # Validation
    with torch.no_grad():
        validation_loss = mini_batch(device, validation_loader, validation_step_fn)
        validation_losses.append(validation_loss)

    # Records both losses
    writer.add_scalars(main_tag='loss', tag_scalar_dict={'training': loss, 'validation': validation_loss}, global_step=epoch)

    if epoch % 10 == 0:
        print(f'Epoch: {epoch}, Train Loss: {loss:.4f}, Validation Loss: {validation_loss:.4f}')

        checkpoint = {
            'epoch': epoch,
            'model_state_dict': model.state_dict(),
            'optimizer_state_dict': optimizer.state_dict(),
            'loss': loss,
            'validation_loss': validation_loss
        }
        torch.save(checkpoint, 'checkpoint.pth')

writer.close()
display(model.state_dict(), optimizer.state_dict())
