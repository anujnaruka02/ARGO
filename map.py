def create_map(cust,hotel):
    m = folium.Map(location=[cust.Lat.mean(), cust.Lon.mean()], zoom_start=12, tiles='OpenStreetMap')
    
   
    
    for _, row in cust.iterrows():
         
        if row['Condition']=='Out':
            cluster_colour='blue'
        else:
            cluster_colour = 'green'
        
        folium.CircleMarker(
            location= [row['Lat'],row['Lon']],
            radius=5,
            popup= row[['Condition','Location']],
            color=cluster_colour,
            fill=True,
            fill_color=cluster_colour
            ).add_to(m)
    
    for _, row in hotel.iterrows(): 
        folium.Marker(
            location= [row['Lat'],row['Lon']],
            radius=5,
            popup= row['Seller'],
            color='red',
            fill=True,
            fill_color='red'
             ).add_to(m)
    for _, row in hotel.iterrows(): 
        folium.Circle(
            location= [row['Lat'],row['Lon']],
            radius=3000,
            popup= row['Seller'],
            color='black',
            fill=False,
        ).add_to(m)
        
    return m