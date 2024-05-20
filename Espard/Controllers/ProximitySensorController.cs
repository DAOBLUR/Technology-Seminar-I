using Microsoft.AspNetCore.Mvc;
using System.Diagnostics.Metrics;

namespace Espard.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class ProximitySensorController : ControllerBase
    {
        public static int CurrentDistance { get; set; } = -1;

        [HttpGet]
        [Route("SetDistance")]
        public async Task<IActionResult> SetDistance(int distance)
        {
            if (distance > 0)
            {
                CurrentDistance = distance;
            }

            return Ok(distance);
        }

        [HttpGet]
        [Route("GetDistance")]
        public async Task<IActionResult> GetDistance()
        {
            if (CurrentDistance > 0)
            {
                return Ok($"{CurrentDistance} cm");
            }

            return Ok($"Error");
        }
    }
}
