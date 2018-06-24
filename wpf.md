### Textbox interactive 
```wpf
<TextBlock Text="Search path:" VerticalAlignment="Center"/>
            <TextBox Width="200" Margin="5,0,0,0">
                <Binding Path="SearchPath" UpdateSourceTrigger="PropertyChanged" Mode="TwoWay"/>
</TextBox>
```

### creating style
```wpf
        <Style x:Key="ValuePanelStyle">
            <Setter Property="Control.Visibility" Value="Visible" />
            <Style.Triggers>
                <DataTrigger Binding="{Binding Path=Value}" Value="{x:Null}">
                    <Setter Property="Control.Visibility" Value="Hidden" />
                </DataTrigger>
            </Style.Triggers>
        </Style>
```

### executing in UI thread

```csharp
    // Application.Current.Dispatcher is main dispatcher
       public static void Execute(this Dispatcher dispatcher, Action action)
        {
            dispatcher.BeginInvoke(
                new DispatcherOperationCallback(
                    (a) =>
                        {
                            action();
                            return null;
                        }),
                new object[] { "a" });
        }
```

### refreshing button
```csharp
    CommandManager.InvalidateRequerySuggested
```